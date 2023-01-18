# Inthegame SmartTV - Apple TV SDK

This SDK allows you to easily integrate the In The Game engagement platform in a Smart TV app. It is compatible with Apple tvOS devices.\
The repository includes an example app that shows how to use the framework.\


## Installation

To install, drag **Inthegametv.xcframework**, **Storket.xcframework** into your project. 

Configure the framework as Embedded on your project target settings:

![](https://i.imgur.com/cv6yIdU.png)


And import the SDK in your code:

`import Inthegametv`

## Usage

To display interactive content, you add the ITGOverlayView over your video player.
Define a variable:

```
var overlayView: ITGOverlayView?
```

And configure it on `viewDidLoad`:
```
var environment = ITGEnvironment.test
let overlay = ITGOverlayView(frame: view.bounds)
overlay.translatesAutoresizingMaskIntoConstraints = true
overlay.autoresizingMask = [.flexibleWidth, .flexibleHeight]
yourContainerView.addSubview(overlay)
overlay.load(channelSlug: "<your_channel_slug>", accountId: "<your_account_id>", environment: environment, delegate: <self>, language: "<your language>")
overlay.injectionDelay = nil
overlayView = overlay
```

The overlay needs to be informed whenever the video is paused, starts playing, or if the user seeks to a different time position, so that it knows when to show content.\
So you call these methods when the video player state is changed:
```
overlayView?.videoPlaying(time: Value)
overlayView?.videoPaused(time: Value)
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

If you want to connect ITG content with your user's account, there are variable in the `load()` method where you can specify your user's ID. The variable are called `foreignId`.


## Custom Environments

If you are provided with custom environment settings, please specify them before loading the overlay:
```
var environment = ITGEnvironment(apiBaseURL = "xxxxx", imageBaseURL = "xxxxx", envName = "xxxxx")

```
