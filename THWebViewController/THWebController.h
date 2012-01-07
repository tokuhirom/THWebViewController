//
// Copyright 2011 Roger Chapman
// Copyright 2011 Benedikt Meurer
// Copyright 2012 Tokunaga HIromu
//
// Forked from Three20 July 29, 2011 - Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @defgroup NimbusWebController Nimbus Web Controller
 * @{
 *
 * This controller presents a UIWebView with a toolbar containing basic chrome for interacting
 * with it. The chrome shows forward, back, stop and refresh buttons on a toolbar aligned
 * to the bottom of the view controller's view. The toolbar includes an option to open the
 * URL in Safari. If the controller is shown in a navigation controller, self.title will
 * show the current web page's title. A spinner will be shown in the navigation bar's right
 * bar button area if there are any active requests.
 *
 *
 * <h2>Adding the Web Controller to Your Application</h2>
 *
 * The web controller uses a small number of custom icons that are stored in the
 * NimbusWebController bundle. You must add this bundle to your application, ensuring
 * that you select the "Create Folder References" option and that the bundle is
 * copied in the "Copy Bundle Resources" phase.
 *
 * The bundle can be found at <code>src/webcontroller/resources/NimbusWebController.bundle</code>.
 *
 *
 * <h2>Future Goals</h2>
 *
 * - Better use of screen real estate on the iPad. We will ideally provide multiple implementation
 *   styles. For example: native Safari, with the toolbar at the top; native Twitter, with the
 *   toolbar at the bottom; plain, with no toolbar at all.
 *
 *
 * <h2>Example Applications</h2>
 *
 * <h3>Basic Web Controller</h3>
 *
 * <a
 * href="https://github.com/jverkoey/nimbus/tree/master/examples/webcontroller/BasicWebController">
 * View the README on GitHub</a>
 *
 * This sample application demos the use of the web controller on the iPhone and iPad.
 *
 * <h2>Screenshots</h2>
 *
 * @image html webcontroller-iphone-example1.png "Screenshot of a basic web controller on the iPhone"
 *
 * @}*/

/**
 * A simple web view controller implementation with a toolbar.
 *
 *      @ingroup NimbusWebController
 *
 *
 * <h2>Subclassing</h2>
 *
 * This view controller implements UIWebViewDelegate. If you want to
 * implement methods of this delegate then you should take care to call the super implementation
 * if necessary. The following UIViewWebDelegate methods have implementations in this class:
 *
 * @code
 * - webView:shouldStartLoadWithRequest:navigationType:
 * - webViewDidStartLoad:
 * - webViewDidFinishLoad:
 * - webView:didFailLoadWithError:
 * @endcode
 *
 * This view controller also implements UIActionSheetDelegate. If you want to implement methods of
 * this delegate then you should take care to call the super implementation if necessary. The
 * following UIActionSheetDelegate methods have implementations in this class:
 *
 * @code
 * - actionSheet:clickedButtonAtIndex:
 * - actionSheet:didDismissWithButtonIndex:
 * @endcode
 *
 * In addition to the above methods of the UIActionSheetDelegate, this view controller also provides
 * the following method, which is invoked prior to presenting the internal action sheet to the user
 * and allows subclasses to customize the action sheet or even reject to display it (and provide their
 * own handling instead):
 *
 * @code
 * - shouldPresentActionSheet:
 * @endcode
 *
 *
 * <h2>Recommended Configurations</h2>
 *
 * <h3>Default</h3>
 *
 * The default settings will create a toolbar with the default tint color, which is normally
 * light blue on the iPhone and gray on the iPad.
 *
 *
 * <h3>Colored Toolbar</h3>
 *
 * The following settings will change the toolbar tint color (in this case black)
 *
 * @code
 *  [webController setToolbarTintColor:[UIColor blackColor]];
 * @endcode
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface THWebController : UIViewController <
  UIWebViewDelegate,
  UIActionSheetDelegate > {
@protected
  // Views
  UIWebView*        _webView;
  UIToolbar*        _toolbar;
  UIActionSheet*    _actionSheet;
  
  // Toolbar buttons
  UIBarButtonItem*  _backButton;
  UIBarButtonItem*  _forwardButton;
  UIBarButtonItem*  _refreshButton;
  UIBarButtonItem*  _stopButton;
  UIBarButtonItem*  _actionButton;
  UIBarButtonItem*  _activityItem;

  NSURL*            _actionSheetURL;
  NSURL*            _loadingURL;
}

/**
 * The current web view URL.
 *
 * If the web view is currently loading a URL then the loading URL is returned instead.
 */
- (NSURL *)URL;

/**
 * Opens the given URL in the web view.
 */
- (void)openURL:(NSURL*)URL;

/**
 * Load the given request using UIWebView's loadRequest:.
 *
 *      @param request  A URL request identifying the location of the content to load.
 */
- (void)openRequest:(NSURLRequest*)request;

/**
 * Sets the visibility of the toolbar.
 *
 * If the toolbar is hidden then the web view will take up the controller's entire view.
 */
- (void)setToolbarHidden:(BOOL)hidden;

/**
 * Sets the toolbar to the given color.
 */
- (void)setToolbarTintColor:(UIColor*)color;

/**
 * This message is send to the receiver in response to the user clicking the action toolbar button.
 *
 * You can provide your own implementation in your subclass and customize the @c actionSheet
 * that is shown to the user or even cancel the presentation of the @c actionSheet by
 * returning @c NO from your implementation.
 *
 * @param actionSheet The UIActionSheet that will be presented to the user.
 *
 * @return @c YES to present the @p actionSheet, @c NO if you want to perform a custom action.
 */
- (BOOL)shouldPresentActionSheet:(UIActionSheet *)actionSheet;

@end
