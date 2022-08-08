import os
def upload(port : str, src_path : str, arduino_dir : str = "C:\\Program Files (x86)\\Arduino", use_debug : bool = True) -> bool:
    arduino_bin = "arduino_debug.exe" if use_debug else "arduino.exe"
    arduino_bin_full_path = os.path.join(arduino_dir, arduino_bin)
    if not os.path.isfile(arduino_bin_full_path):
        return False

    upload_command = f"\"{arduino_bin_full_path}\" --board arduino:avr:uno --port {port} --upload {src_path}"

    ret_code = os.system(upload_command)
    return True if ret_code == 0 else False
    
upload("포트", "소스코드 이름", "arduino ide가 설치된 폴더 경로")