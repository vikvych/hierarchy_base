Pod::Spec.new do |s|
  s.name         = "HierarchyBase"
  s.version      = "0.0.1"
  s.summary      = "HierarchyBase for SafeUM"
  s.description  = "HierarchyBase is base kernel tool for SafeUM"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.source       = { :git => "https://github.com/vikvych/hierarchy_base.git", :tag => s.version.to_s }
  s.homepage     = "https://github.com/vikvych"
  s.authors      = { 'SafeUM' => 'info@safeum.com' }

  s.ios.deployment_target   = '8.0'
  s.source_files        = 'Include/**/*.h'
  s.public_header_files = 'Include/**/*.h'
  s.header_mappings_dir = 'Include'
  s.preserve_paths      = 'Library/libHierarchyBase.a'
  s.vendored_libraries  = 'Library/libHierarchyBase.a'

  s.libraries = 'hierarchyBase'
  s.requires_arc = false

  s.dependency 'SumOpenSSL'
end
