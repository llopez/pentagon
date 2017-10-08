module Api
  module V1
    class DevicesController < ActionController::API
      include ActionController::HttpAuthentication::Token::ControllerMethods

      before_action :set_device, only: [:show, :update, :destroy]
      before_action :authenticate

      def menu

        devices =  Device.all

        menu = devices.map do |d|
          {
            name: d.name,
            menu: [
              {name: 'on', field: 'state', value: 'on', path: "/api/v1/devices/#{d.id}"},
              {name: 'off', field: 'state', value: 'off', path: "/api/v1/devices/#{d.id}"},
            ]
          }
        end

        render json: menu


      end

      def index
        @devices = Device.all
        render json: @devices
      end

      def show
        render json: @device
      end

      def create
        @device = Device.new(device_params)

        if @device.save
          render json: @device, status: :created
        else
          render json: @device.errors, status: :unprocessable_entity
        end
      end

      def update
        if @device.update(device_params)
          render json: Device.all
        else
          render json: @device.errors, status: :unprocessable_entity
        end
      end

      def destroy
        @device.destroy
        head :no_content
      end

      private

      def authenticate_token
        authenticate_with_http_token do |token, options|
          @current_user = User.find_by(auth_token: token)
        end
      end

      def authenticate
        authenticate_token || render_unauthorized
      end

      def render_unauthorized
        head :unauthorized
      end

      def set_device
        @device = Device.find(params[:id])
      end

      def device_params
        params.permit(:name, :state, :ip_address, :type, :pinged_at, :chipid, :streaming_url)
      end
    end
  end
end
