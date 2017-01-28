module Api
  module V1
    class DevicesController < ActionController::API
      before_action :set_device, only: [:show, :update, :destroy]

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
          render :show, status: :created, location: @device
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

      def set_device
        @device = Device.find(params[:id])
      end

      def device_params
        params.permit(:name, :state, :ip_address, :pinged_at)
      end
    end
  end
end
