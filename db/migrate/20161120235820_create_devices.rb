class CreateDevices < ActiveRecord::Migration[5.0]
  def change
    create_table :devices do |t|
      t.string :name
      t.string :state
      t.string :ip_address
      t.datetime :pinged_at

      t.timestamps
    end
  end
end
