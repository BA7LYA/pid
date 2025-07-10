cd vcpkg
git pull
.\bootstrap-vcpkg.bat -disablemetrics
.\vcpkg x-update-baseline
cd ..