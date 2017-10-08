class Switch < Device
  before_save :send_message, if: :state_changed?
  after_initialize :set_default_values

  validates :name, :state, presence: true

  def set_default_values
    self.state ||= 'off'
  end
end
