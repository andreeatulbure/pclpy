
IF not exist pcl-pcl-1.9.1/nul ( powershell -ExecutionPolicy ByPass -File scripts\download_pcl.ps1 )

IF not exist pclpy/src/generated_modules/nul ( call scripts\generate_points_and_bindings.bat )

python -m pip install . --no-deps