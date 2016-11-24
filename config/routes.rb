Rails.application.routes.draw do
  resources :devices

  get 'dashboard' => 'dashboard#show', as: :dashboard

  root to: 'devices#index'
end
