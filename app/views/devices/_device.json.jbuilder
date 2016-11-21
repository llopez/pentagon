json.extract! device, :id, :name, :state, :ip_address, :pinged_at, :created_at, :updated_at
json.url device_url(device, format: :json)
