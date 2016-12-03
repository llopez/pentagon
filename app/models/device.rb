class Device < ApplicationRecord
  before_save :send_message, if: :state_changed?

  # state: on, off, turning_on, turning_off

  def send_message
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.publish("device/#{id}", state == 'on' ? 1 : 0 )
      #puts c.get("device/#{id}/ack").class
    end
  end
end

# before_save -> background(sub -t device/:id/ack) ActiveJob + sidekiq
# after_save -> pub -t device/:id/control -m ON
