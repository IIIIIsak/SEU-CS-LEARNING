import socket

if __name__ =='__main__':

    # 新建监听 socket
    welcom_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    #监听所有的 ip 的 20000 端口
    welcom_socket.bind( ("0.0.0.0",20000))

    # 只监听一个 TCP连接
    welcom_socket.listen(1)

    while True:
        connection_socket, addr = welcom_socket.accept()    #接收TCP连接请求，并返回一个传输用的套接字
        print("连接成功")
        #接收信息
        buffer = []
        print("接收字节")
        #一次接收1k字节
        d = connection_socket.recv(1024)
        buffer.append(d)
        print("接收完成")
        sentence = b''.join(buffer).decode()   #获取消息
        sentence += ' hello '                  #修改信息
        print(sentence)
        # 发送消息
        connection_socket.send(sentence.encode())
        # 关闭TCP连接
        connection_socket.close()

