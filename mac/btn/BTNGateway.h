//
//  BTNGateway.h
//  btn
//
//  Created by Kyle Banks on 2014-06-15.
//  Copyright (c) 2014 Kyle W. Banks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ORSSerialPort.h"

typedef enum BTNCommand {
    BTN_PRESSED
} BTNCommand;

@class BTNGateway;

@protocol BTNGatewayDelegate <NSObject>
//Once the BTN has been discovered
-(void)btnGateway:(BTNGateway *)gateway didInitializeBTN:(ORSSerialPort *)btnSerialPort;
//Received a command from BTN
-(void)btnGateway:(BTNGateway *)gateway didReceiveCommand:(BTNCommand)command;
//Connection lost to BTN
-(void)btnGateway:(BTNGateway *)gateway lostConnectionToBTN:(ORSSerialPort *)btnSerialPort;
@end

@interface BTNGateway : NSObject <ORSSerialPortDelegate>

+(BTNGateway *)sharedGateway;

+(void)addBtnGatewayDelegate:(id<BTNGatewayDelegate>)delegate;

@end