import datetime
import requests
import psutil
import socket
import json
import win32serviceutil
import win32service
import win32event
import time
DINGTALK_WEBHOOK_URL = "https://oapi.dingtalk.com/robot/send?access_token=77d6eeaead1d91ab03cdcda2a175d5fa0e64ca438fa98027ef607a8868675d2d"

# 获取本地IPv6地址
def get_public_ip():
    # 获取本地主机名
    hostname = socket.gethostname()
    # 获取本机IPv6地址
    ipv6_address = None
    addrs = psutil.net_if_addrs()
    for interface, addresses in addrs.items():
        for address in addresses:
            if address.family == socket.AF_INET6 and not address.address.startswith('fe80:'):
                ipv6_address = address.address
                break
        if ipv6_address:
            break
    return ipv6_address
 
def message(text):
    headers = {'Content-Type': 'application/json'}
    payload = {
        "msgtype": "text",
        "text": {
            "content": "ipv6"+text
        }
    }
    response = requests.post(DINGTALK_WEBHOOK_URL, json=payload, headers=headers)
 
  
 
class PythonService(win32serviceutil.ServiceFramework):
    _svc_name_ = "Send IP"  # 服务名
    _svc_display_name_ = "Send IP"  # 服务在windows系统中显示的名称
    _svc_description_ = "Send My Computer IP to me"  # 服务的描述
 
    def __init__(self, args):
        win32serviceutil.ServiceFramework.__init__(self, args)
        self.hWaitStop = win32event.CreateEvent(None, 0, 0, None)
        self.run = True
        self.local_ip = None
 
    def SvcDoRun(self):
        while self.run:
            try:
                now = datetime.datetime.now()
                if now.minute == 0 or now.minute == 15:  # 每小时0分、30分检测一次ip变化
                    IP = get_public_ip()
                    if self.local_ip != IP:
                        self.local_ip = IP
                        if IP:
                            message("地址已更新：" + IP)
            except:
                pass
            time.sleep(1)  # 每隔60秒检查一次
 
    def SvcStop(self):
        self.ReportServiceStatus(win32service.SERVICE_STOP_PENDING)
        win32event.SetEvent(self.hWaitStop)
        self.run = False
 
if __name__ == '__main__':
    win32serviceutil.HandleCommandLine(PythonService)