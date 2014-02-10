//
//  BCQCCableConnectionsPrincipal.m
//  QCCableConnections
//
//  Created by Bartosz Ciechanowski on 08.02.2014.
//  Copyright (c) 2014 Bartosz Ciechanowski. All rights reserved.
//

#import "BCQCCableConnectionsPrincipal.h"
#import "CGPointVectors.h"

typedef struct Beziers {
    CGPoint p[8];
} Beziers;


Beziers curvyBeziersWithFromToPoint(CGPoint from, CGPoint to)
{
    const CGFloat MinX = 15.0;
    
    const CGFloat StartOffset = 10.0;
    const CGFloat c = 0.17;
    
    CGPoint fromTip = CGPointAdd(from, CGPointMake(StartOffset, 0));
    CGPoint toTip = CGPointSub(to, CGPointMake(StartOffset, 0));
    
    CGPoint diff = CGPointSub(toTip, fromTip);
    
    Beziers b;
    b.p[0] = CGPointAdd(from, CGPointMake(StartOffset, 0));
    b.p[1] = CGPointAdd(b.p[0], CGPointMake(MAX(MinX, diff.x/6.0), 0));
    b.p[2] = CGPointAdd(b.p[1], CGPointScale(diff, c));
    b.p[2].x = MAX(b.p[2].x, b.p[1].x);
    
    b.p[3] = b.p[4] = CGPointAdd(b.p[0], CGPointScale(diff, 0.5));
    
    b.p[7] = CGPointSub(to, CGPointMake(StartOffset, 0));
    b.p[6] = CGPointSub(b.p[7], CGPointMake(MAX(MinX, diff.x/6.0), 0));
    b.p[5] = CGPointSub(b.p[6], CGPointScale(diff, c));
    b.p[5].x = MIN(b.p[5].x, b.p[6].x);
    
    return b;
}

Beziers straightBeziersWithFromToPoint(CGPoint from, CGPoint to)
{
    const CGFloat StartOffset = 10.0;
    const CGFloat MinX = 6.0;
    
    CGPoint fromTip = CGPointAdd(from, CGPointMake(StartOffset + MinX, 0));
    CGPoint toTip = CGPointSub(to, CGPointMake(StartOffset + MinX, 0));
    
    CGPoint diff = CGPointSub(toTip, fromTip);
    CGFloat len = sqrt(diff.x * diff.x + diff.y * diff.y);
    CGPoint dir = CGPointScale(diff, 1.0/len);
    
    Beziers b;
    b.p[0] = CGPointAdd(from, CGPointMake(StartOffset, 0));
    b.p[1] = fromTip;
    b.p[2] = CGPointAdd(b.p[1], CGPointScale(dir, MinX));
    b.p[3] = CGPointAdd(b.p[2], CGPointScale(dir, MinX));
    
    b.p[7] = CGPointSub(to, CGPointMake(StartOffset, 0));
    b.p[6] = toTip;
    b.p[5] = CGPointSub(b.p[6], CGPointScale(dir, MinX));
    b.p[4] = CGPointSub(b.p[5], CGPointScale(dir, MinX));
    
    return b;
}


@implementation BCQCCableConnectionsPrincipal

+ (void)initialize
{
    SwizzleInstanceMethod([GFGraphView class], @selector(boundsForConnection:fromPoint:toPoint:), @selector(BC_boundsForConnection:fromPoint:toPoint:));
    SwizzleInstanceMethod([QCPatchView class], @selector(drawConnection:fromPoint:toPoint:), @selector(BC_drawConnection:fromPoint:toPoint:));
    SwizzleInstanceMethod([QCPatchView class], @selector(_drawConnection:fromPort:point:toPoint:), @selector(BC__drawConnection:fromPort:point:toPoint:));
}

+ (void)registerNodesWithManager:(GFNodeManager*)manager
{
    
}

void SwizzleInstanceMethod(Class c, SEL orig, SEL new)
{
    Method origMethod = class_getInstanceMethod(c, orig);
    Method newMethod = class_getInstanceMethod(c, new);
    
    if(class_addMethod(c, orig, method_getImplementation(newMethod), method_getTypeEncoding(newMethod))) {
        class_replaceMethod(c, new, method_getImplementation(origMethod), method_getTypeEncoding(origMethod));
    } else {
        method_exchangeImplementations(origMethod, newMethod);
    }
}

@end




@implementation QCPatchView(CustomConnectionDrawing)

- (BOOL) BC_isInteractionPort:(GFPort *)port
{
    return [port.originalPort isKindOfClass:[QCInteractionPort class]];
}

- (void)BC_drawConnection:(QCLink *)link fromPoint:(NSPoint)from toPoint:(NSPoint)to
{
    [self BC_drawActualConnection:link fromPort:link.sourcePort fromPoint:from toPoint:to];
}

- (void)BC__drawConnection:(QCLink *)link fromPort:(GFPort *)port point:(NSPoint)from toPoint:(NSPoint)to
{
    [self BC_drawActualConnection:link fromPort:port fromPoint:from toPoint:to];
}

- (void)BC_drawActualConnection:(QCLink *)link fromPort:(GFPort *)port fromPoint:(NSPoint)from toPoint:(NSPoint)to
{
    [[NSGraphicsContext currentContext] saveGraphicsState];
    
    Beziers b = [self BC_isInteractionPort:port] ? straightBeziersWithFromToPoint(from, to) : curvyBeziersWithFromToPoint(from, to);
    
    NSBezierPath *path = [NSBezierPath bezierPath];
    
    [path moveToPoint:from];
    [path lineToPoint:b.p[0]];
    [path curveToPoint:b.p[3] controlPoint1:b.p[1] controlPoint2:b.p[2]];
    [path lineToPoint:b.p[4]];
    [path curveToPoint:b.p[7] controlPoint1:b.p[5] controlPoint2:b.p[6]];
    [path lineToPoint:to];
    
    [path setLineCapStyle:NSRoundLineCapStyle];
    
    [path setLineWidth:4.0];
    [[NSColor colorWithCalibratedWhite:0.0 alpha:0.7] setStroke];
    [path stroke];
    
    [path setLineWidth:2.0];
    [[self _colorForConnection:link] setStroke];
    [path stroke];
    
    [[NSGraphicsContext currentContext] restoreGraphicsState];
}

@end


@implementation GFGraphView(CustomConnectionDrawing)

- (NSRect)BC_boundsForConnection:(id)fp8 fromPoint:(NSPoint)from toPoint:(NSPoint)to
{
    return CGRectInset(CGRectMake(MIN(from.x, to.x), MIN(from.y, to.y), fabs(from.x - to.x), fabs(from.y - to.y)), -30, -30);
}

@end