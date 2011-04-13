require 'spec_helper'
require 'capybara/driver/webkit'

describe Capybara::Driver::Webkit do
  before do
    @driver = Capybara::Driver::Webkit.new(TestApp, :browser => $webkit_browser)
  end

  # TODO: select options
  # it_should_behave_like "driver"

  # TODO: bug with drag and drop
  # it_should_behave_like "driver with javascript support"

  it_should_behave_like "driver with cookies support"
  it_should_behave_like "driver with header support"

  # Can't support:
  # it_should_behave_like "driver with status code support"
  # it_should_behave_like "driver with frame support"
end
