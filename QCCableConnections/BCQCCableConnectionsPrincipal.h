//
//  BCQCCableConnectionsPrincipal.h
//  QCCableConnections
//
//  Created by Bartosz Ciechanowski on 08.02.2014.
//  Copyright (c) 2014 Bartosz Ciechanowski. All rights reserved.
//


@interface BCQCCableConnectionsPrincipal : NSObject <GFPlugInRegistration>

+ (void)registerNodesWithManager:(QCNodeManager*)manager;

@end
