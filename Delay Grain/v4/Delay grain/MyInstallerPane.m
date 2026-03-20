//
//  MyInstallerPane.m
//  Delay grain
//
//  Created by Victor Schulhoff on 3/20/26.
//

#import "MyInstallerPane.h"

@implementation MyInstallerPane

- (NSString *)title
{
    return [[NSBundle bundleForClass:[self class]] localizedStringForKey:@"PaneTitle" value:nil table:nil];
}

@end
