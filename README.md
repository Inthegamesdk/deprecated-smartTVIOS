# Inthegame SmartTV - Apple TV SDK

This SDK allows you to easily integrate the In The Game engagement platform in a Smart TV app. It is compatible with Apple tvOS devices.\
The repository includes an example app that shows how to use the framework.\
The example uses CocoaPods, so you'll need to run `pod install` and open the workspace file to run it.


## Installation

To install, drag **Inthegametv.xcframework** into your project. 

Configure the framework as Embedded on your project target settings:

![](https://i.imgur.com/4PWyk71.png)


And import the SDK in your code:

`import Inthegametv`

The framework requires the Pusher library. If you are using CocoaPods, add this line to your podfile:

`pod 'PusherSwift'`

After running `pod install` there is one more setting you'll need to tweak. Open your workspace and select the Pods project file. You'll see 3 new targets for the dependencies: `PusherSwift`, `NWWebSocket` and `TweetNacl`. For each of them, go to `Build Settings` and switch `Build Libraries for Distribution` to Yes.

## Usage

To display interactive content, you add the ITGOverlayView over your video player.
Define a variable:

```
var overlayView: ITGOverlayView?
```

And configure it on `viewDidLoad`:
```
let overlay = ITGOverlayView(frame: view.bounds)
overlay.translatesAutoresizingMaskIntoConstraints = true
overlay.autoresizingMask = [.flexibleWidth, .flexibleHeight]
containerView.addSubview(overlay)
        
overlay.load(channelID: "<your_channel_id>", broadcasterName: "<your_broadcaster_name>", delegate: self)
overlayView = overlay
```

The overlay needs to be informed whenever the video is paused, starts playing, or if the user seeks to a different time position, so that it knows when to show content.\
So you call these methods when the video player state is changed:
```
overlayView?.videoPlaying(time: time)
overlayView?.videoPaused()
```

To allow the user to close interactions with the menu button, you can pass your menu button events to the overlay.\
The method will return true if the overlay uses the event to close content. If false, you should perform your app's default back action.
```
let usedEvent = overlayView?.closeInteractionIfNeeded() ?? false
```

Some interactive content requires a pause in the video. To use this feature, override the ITGOverlayDelegate methods to detect when it requests these events.
```
func overlayRequestedPause()
func overlayRequestedPlay()
```

The overlay will request focus when showing content, so that the user can interact with the buttons. Use these delegate methods to set the preferredFocusView of your controller accordingly.\
The example app includes a basic setup of the focus transfer.
```
func overlayRequestedFocus()
func overlayReleasedFocus()
```

If you want to connect ITG content with your user's account, there are variables in the `load()` method where you can specify your user's ID and display name. The variables are called `userBroadcasterForeignID` and `userInitialName`.


## Optional Customization

You can also adjust the bottom margin for the content, and the type of animation:
```
overlay.bottomMargin = 0
overlay.animationType = .fromBottom
```

If you want to replace our content visuals with your own customizable interfaces, you can implement the layout delegate:
```
overlay.layoutDelegate = self
```
Then you can create subclasses of our content views with customized layouts, and provide them in the delegate methods. A full working example is included in the repository. The delegate methods are: 
```
func customPollView() -> ITGPollView?
func customRatingView() -> ITGRatingView?
func customTriviaView() -> ITGTriviaView?
func customNoticeView() -> ITGNotice?
```
