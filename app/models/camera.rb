class Camera < Device
  validates :name, :ip_address, presence: true
end