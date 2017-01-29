class IconidColumnToDevices < ActiveRecord::Migration[5.0]
  def change
    add_column :devices, :iconid, :string
  end
end
