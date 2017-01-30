class User < ApplicationRecord
  has_secure_password

  before_create :generate_token

  def generate_token
    self.auth_token = SecureRandom.hex
  end
end
