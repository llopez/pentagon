class Ir < Device
  before_save :send_message, if: :state_changed?
  validates :name, presence: true
end