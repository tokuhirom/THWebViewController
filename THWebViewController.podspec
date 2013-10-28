Pod::Spec.new do |s|
  s.name         = "THWebViewController"
  s.version      = "0.0.1"
  s.summary      = "Minimalistic WebViewController"
  s.homepage     = "https://github.com/tokuhirom/THWebViewController"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = "Tokuhiro Matsuno"
  s.platform     = :ios, '5.0'
  s.source       = { :git => "https://github.com/tokuhirom/THWebViewController.git", :commit => "113abd404adb42f32741f9f97f3b6cebb6974c84" }
  s.source_files = 'THWebViewController/*.{h,m}'
  s.resource     = "THWebViewController/THWebController.bundle"
  s.requires_arc = true
end
