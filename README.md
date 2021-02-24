# Inthegame SmartTV - Apple TV SDK

This SDK allows you to easily integrate the In The Game engagement platform in a Smart TV app. It is compatible with Apple tvOS devices.\
The repository includes an example app that shows how to use the framework.\
The example uses CocoaPods, so you'll need to run `pod install` and open the workspace file to run it.


## Installation

To install, drag **Inthegametv.framework** into your project. 

Configure the framework as Embedded on your project target settings:

![](https://imgur.com/J55NVJn.jpg)


And import the SDK in your code:

`import Inthegametv`

The framework requires the Socket.IO-Client library. If you are using CocoaPods, add this line to your podfile:

`pod 'Socket.IO-Client-Swift', '~> 15.2.0'`

If the framework fails to run in the simulator, you'll need to exclude arm64 architectures in your project's build settings:

![](https://imgur.com/qNRmq1D.jpg)


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
fun overlayRequestedPause()
fun overlayRequestedPlay()
```

The overlay will request focus when showing content, so that the user can interact with the buttons. Use these delegate method to set the preferredFocusView of your controller accordingly.\
The example app includes a basic setup of the focus transfer.
```
func overlayRequestedFocus()
func overlayReleasedFocus()
```


