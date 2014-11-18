postmaster
==========

in __Appdelegate.m__

```
-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
...
_contentCache = [[NSCache alloc] init];
```

In __SomeClass.h__

```
#import "Postmaster.h"
...
@property (nonatomic) AppDelegate *appDelegate;
@property (nonatomic) Postmaster *postmaster;
@property (nonatomic) NSCache *contentCache;
```

In __SomeClass.m__

```
-(id) init {
        _appDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
        _postmaster = [[Postmaster alloc] init];
        _contentCache = [_appDelegate contentCache];
        
        return self
}
```

Example Usage

```
dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0ul);
			
	dispatch_async(queue, ^{
				
		NSData *imageData = [_postmaster getAndReceive:[NSURL URLWithString:[cellData valueForKey:@"icon"]] packageData:nil cachable:YES];
				
		dispatch_sync(dispatch_get_main_queue(), ^{
					
			[contentsImage setImage:[UIImage imageWithData:imageData]];
					
		});
				
});
```
