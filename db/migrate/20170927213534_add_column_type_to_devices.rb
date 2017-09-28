class AddColumnTypeToDevices < ActiveRecord::Migration[5.0]
  def change
    add_column :devices, :type, :string
  end
end
