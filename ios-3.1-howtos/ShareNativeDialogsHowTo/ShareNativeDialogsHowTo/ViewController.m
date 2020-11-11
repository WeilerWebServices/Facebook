/*
 * Copyright 2012 Facebook
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "ViewController.h"
#import "AppDelegate.h"
#import "ShareViewController.h"

@interface ViewController ()
@property (unsafe_unretained, nonatomic) IBOutlet UIButton *authButton;
@property (unsafe_unretained, nonatomic) IBOutlet UIButton *publishButton;

@end

@implementation ViewController

@synthesize authButton;

#pragma mark - Helper methods

/*
 * Configure the logged in versus logged out UI
 */
- (void)sessionStateChanged:(NSNotification*)notification {
    if (FBSession.activeSession.isOpen) {
        self.publishButton.hidden = NO;
        [self.authButton setTitle:@"Logout" forState:UIControlStateNormal];
    } else {
        self.publishButton.hidden = YES;
        [self.authButton setTitle:@"Login" forState:UIControlStateNormal];
    }
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    // Register for notifications on FB session state changes
    [[NSNotificationCenter defaultCenter]
     addObserver:self
     selector:@selector(sessionStateChanged:)
     name:FBSessionStateChangedNotification
     object:nil];
    
    // Check the session for a cached token to show the proper authenticated
    // UI. However, since this is not user intitiated, do not show the login UX.
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    [appDelegate openSessionWithAllowLoginUI:NO];
}

- (void)viewDidUnload
{
    [self setAuthButton:nil];
    [self setPublishButton:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

#pragma mark - Action methods
- (IBAction)authButtonAction:(id)sender {
    AppDelegate *appDelegate =
    [[UIApplication sharedApplication] delegate];
    
    // The user has initiated a login, so call the openSession method
    // and show the login UX if necessary.
    //[appDelegate openSessionWithAllowLoginUI:YES];
    
    // If the user is authenticated, log out when the button is clicked.
    // If the user is not authenticated, log in when the button is clicked.
    if (FBSession.activeSession.isOpen) {
        [appDelegate closeSession];
    } else {
        // The user has initiated a login, so call the openSession method
        // and show the login UX if necessary.
        [appDelegate openSessionWithAllowLoginUI:YES];
    }
    
    
}

- (IBAction)publishButtonAction:(id)sender {
    // First check if we can use the native dialog, otherwise will
    // use our own
    BOOL displayedNativeDialog =
    [FBNativeDialogs
     presentShareDialogModallyFrom:self
     initialText:@""
     image:[UIImage imageNamed:@"iossdk_logo.png"]
     url:[NSURL URLWithString:@"https://developers.facebook.com/ios"]
     handler:^(FBNativeDialogResult result, NSError *error) {
         
         // Only show the error if it is not due to the dialog
         // not being supporte, i.e. code = 7, otherwise ignore
         // because our fallback will show the share view controller.
         if (error && [error code] == 7) {
             return;
         }
         
         NSString *alertText = @"";
         if (error) {
             alertText = [NSString stringWithFormat:
                          @"error: domain = %@, code = %d",
                          error.domain, error.code];
         } else if (result == FBNativeDialogResultSucceeded) {
             alertText = @"Posted successfully.";
         }
         if (![alertText isEqualToString:@""]) {
             // Show the result in an alert
             [[[UIAlertView alloc] initWithTitle:@"Result"
                                         message:alertText
                                        delegate:self
                               cancelButtonTitle:@"OK!"
                               otherButtonTitles:nil]
              show];
         }
    }];
    
    // Fallback, show the view controller that will post using me/feed
    if (!displayedNativeDialog) {
        ShareViewController *viewController =
        [[ShareViewController alloc] initWithNibName:@"ShareViewController"
                                              bundle:nil];
        [self presentViewController:viewController
                           animated:YES
                         completion:nil];
    }
}

@end