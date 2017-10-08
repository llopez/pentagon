class Device < ApplicationRecord
  before_save :generate_slug

  def chipid
    read_attribute(:chipid) || id
  end

  def as_json(options={})
    super(options.merge({:methods => :type}))
  end

  private

  def generate_slug
    self.slug = self.name.split.join("-")
  end

  def send_message
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.publish("/device/#{chipid}", state)
    end

    ActionCable.server.broadcast 'devices_channel', {device_id: self.id, state: self.state}
  end
end
