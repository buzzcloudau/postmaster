//
//  postmaster.h
//  Ricardo Russon ( https://buzzcloud.com.au )
//

#import <Foundation/Foundation.h>
#import "AppDelegate.h"

@class AppDelegate;

@interface Postmaster : NSObject

- (id) init;

- (NSData *) getAndReceive:(NSURL *)uri
               packageData:(NSDictionary *)packageData
                  cachable:(BOOL)cachable;

- (NSDictionary *) getAndReceiveDictionary:(NSURL *)uri
                               packageData:(NSDictionary *)packageData
                                  cachable:(BOOL)cachable;

- (NSData *) postAndReceive:(NSURL *)uri
                packageData:(NSDictionary *)packageData
                   cachable:(BOOL)cachable;

- (NSDictionary *) postAndReceiveDictionary:(NSURL *)uri
                                packageData:(NSDictionary *)packageData
                                   cachable:(BOOL)cachable;

@property (nonatomic) NSCache *contentCache;
@property (nonatomic) AppDelegate *appDelegate;

@end
