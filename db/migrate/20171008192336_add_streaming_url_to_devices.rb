class AddStreamingUrlToDevices < ActiveRecord::Migration[5.0]
  def change
    add_column :devices, :streaming_url, :string
  end
end
