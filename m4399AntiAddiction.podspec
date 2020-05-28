#
# Be sure to run `pod lib lint m4399AntiAddiction.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'm4399AntiAddiction'
  s.version          = '1.0.0'
  s.summary          = '4399防沉迷SDK'


  s.description      = <<-DESC
4399防沉迷SDK
                       DESC

  s.homepage         = 'https://github.com/4399SDKDev/m4399AntiAddiction'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhengxu' => 'zhengxu@4399inc.com' }
  s.source           = { :git => 'https://github.com/4399SDKDev/m4399AntiAddiction.git', :tag => s.version.to_s }


  s.ios.deployment_target = '8.0'

  s.vendored_frameworks = 'm4399AntiAddiction/Framework/m4399AntiAddiction.framework'

end
