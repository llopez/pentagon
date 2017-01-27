Rails.application.routes.draw do
  resources :devices

  get 'dashboard' => 'dashboard#show', as: :dashboard
  get 'api/v1/devices' => 'api/v1/devices#index'
  put 'api/v1/devices/:id' => 'api/v1/devices#update'
  get 'api/v1/devices/:id' => 'api/v1/devices#show'
  patch 'api/v1/devices/:id' => 'api/v1/devices#update'

  root to: 'dashboard#show'
end
