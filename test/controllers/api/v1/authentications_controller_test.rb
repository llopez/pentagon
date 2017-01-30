require 'test_helper'

module Api
  module V1
    class AuthenticationsControllerTest < ActionDispatch::IntegrationTest
      setup do
        @user = users(:luis)
      end

      test "should respond with user" do
        post '/api/v1/auth', params: {email: 'luis@pentagon.com', password: '12345678'}, as: :json

        json_response = JSON.parse(response.body)
        assert_equal({"email" => @user.email, "auth_token" => @user.auth_token}, json_response)
        assert_response :success
      end

      test "should respond with error" do
        post '/api/v1/auth', params: {email: 'luis@pentagon.com', password: 'wrong'}, as: :json

        json_response = JSON.parse(response.body)
        assert_equal({"error" => "email or password invalid"}, json_response)
        assert_response :unauthorized
      end
    end
  end
end
