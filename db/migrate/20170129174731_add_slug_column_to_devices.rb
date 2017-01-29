class AddSlugColumnToDevices < ActiveRecord::Migration[5.0]
  def change
    add_column :devices, :slug, :string
    add_index :devices, :slug
  end
end
