module Api
  module V1
    class AuthenticationsController < ActionController::API
      def create
        @user = User.find_by email: params[:email]

        if @user && @user.authenticate(params[:password])
          render status: :ok
        else  
          render json: {error: 'email or password invalid'}, status: :unauthorized
        end
      end
    end
  end
end

