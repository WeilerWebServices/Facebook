# Copyright (c) 2018-present, Facebook, Inc.
name 'fb_dnsmasq'
maintainer 'Facebook'
maintainer_email 'noreply@facebook.com'
license 'Apache-2.0'
description 'Installs/Configures fb_dnsmasq'
source_url 'https://github.com/facebook/chef-cookbooks/'
long_description IO.read(File.join(File.dirname(__FILE__), 'README.md'))
version '0.1.0'
supports 'centos'
supports 'debian'
supports 'ubuntu'
depends 'fb_ethers'
depends 'fb_hosts'
