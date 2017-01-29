# config valid only for current version of Capistrano
lock "3.7.1"

set :application, "pentagon"
set :repo_url, "git@github.com:llopez/pentagon.git"

# Default branch is :master
# ask :branch, `git rev-parse --abbrev-ref HEAD`.chomp

# Default deploy_to directory is /var/www/my_app_name
set :deploy_to, "/srv/apps/pentagon"

# Default value for :format is :airbrussh.
# set :format, :airbrussh

# You can configure the Airbrussh format using :format_options.
# These are the defaults.
# set :format_options, command_output: true, log_file: "log/capistrano.log", color: :auto, truncate: :auto

# Default value for :pty is false
# set :pty, true

# Default value for :linked_files is []
append :linked_files, "config/database.yml", "config/secrets.yml", "config/cable.yml", "db/production.sqlite3"

# Default value for linked_dirs is []
append :linked_dirs, "log", "tmp/pids", "tmp/cache", "tmp/sockets", "public/system"

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
# set :keep_releases, 5

namespace :deploy do
  desc "Stop rails server"
  task :stop do
    on roles(:app) do
      within current_path do
        execute :kill, "`cat tmp/pids/server.pid`"
      end
    end
  end
  
  desc "Start rails server"
  task :start do
    on roles(:app) do
      within release_path do
        with rails_env: 'production' do
          execute :rails, "server -b 0.0.0.0 -d"
        end
      end
    end
  end
end

before "deploy:symlink:release", "deploy:stop"
after "deploy:symlink:release", "deploy:start"

