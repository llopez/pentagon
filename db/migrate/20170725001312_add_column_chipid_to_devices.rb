class AddColumnChipidToDevices < ActiveRecord::Migration[5.0]
  def change
    add_column :devices, :chipid, :integer
  end
end
