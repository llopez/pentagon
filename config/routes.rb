Rails.application.routes.draw do
  resources :devices

  get 'dashboard' => 'dashboard#show', as: :dashboard
  get 'api/v1/devices' => 'api/v1/devices#index'

  post 'api/v1/devices' => 'api/v1/devices#create'

  get 'api/v1/devices/menu' => 'api/v1/devices#menu'
  
  put 'api/v1/devices/:id' => 'api/v1/devices#update'
  get 'api/v1/devices/:id' => 'api/v1/devices#show'
  patch 'api/v1/devices/:id' => 'api/v1/devices#update'

  

  post 'api/v1/auth' => 'api/v1/authentications#create'


  root to: 'dashboard#show'
end
