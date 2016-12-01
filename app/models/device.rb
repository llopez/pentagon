class Device < ApplicationRecord
  before_save :send_message, if: :state_changed?

  def send_message
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.publish("device/#{id}", state)
    end
  end
end
