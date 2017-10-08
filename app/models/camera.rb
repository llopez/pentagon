class Camera < Device
  validates :name, :streaming_url, presence: true
end