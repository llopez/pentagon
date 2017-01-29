class Device < ApplicationRecord
  before_save :send_message, if: :state_changed?
  before_save :generate_slug

  private

  def generate_slug
    self.slug = self.name.split.join("-")
  end

  def send_message
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.publish("device/#{id}", state == 'on' ? 1 : 0 )
    end

    ActionCable.server.broadcast 'devices_channel', {device_id: self.id, state: self.state}
  end
end
