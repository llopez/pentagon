namespace :mqtt do
  desc "Listen feedback channel and update devices"
  task subscribe: :environment do
    MQTT::Client.connect(Rails.application.secrets.mqtt_server) do |c|
      c.get("device/feedback") do |topic, message|
        id, value = message.split(" ")
        device = Device.find(id)
        device.update_attribute(:state, value)

        ActionCable.server.broadcast 'devices_channel', {device_id: device.id, state: device.state} 
      end
    end
  end
end
