class Ir < Device
  before_save :send_message, if: :state_changed?
  validates :name, presence: true

  private

  def command
    if state == 'on'
      "0x8800909 28"
    elsif state == 'off'
      "0x88C0051 28"
    end
  end

  def send_message
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.publish("/device/#{chipid}", command)
    end

    ActionCable.server.broadcast 'devices_channel', {device_id: self.id, state: self.state}
  end
end
