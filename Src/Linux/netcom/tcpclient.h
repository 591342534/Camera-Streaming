//
// 2015-11-28, jjuiddong
//
// TCP/IP ���������� �̿��ؼ� ����ϴ� ��ü��.
// �ִ��� �����ϰ� �������.
//
// 2016-02-08
//		- linux version �۾�
//
// 2016-09-01
//		- linux version �۾�
//
#pragma once

#include "network.h"


namespace network
{
	class cTCPClient
	{
	public:
		cTCPClient();
		virtual ~cTCPClient();

		bool Init(const string &ip, const int port,
			const int packetSize = 512, const int maxPacketCount = 10, const int sleepMillis = 30,
			const bool isIgnoreHeader = false);
		void Send(BYTE *buff, const unsigned int len);
		void Close();
		bool IsConnect() const;


	public:
		string m_ip;
		int m_port;
		bool m_isConnect;
		SOCKET m_socket;
		int m_maxBuffLen;
		cPacketQueue m_sendQueue;
		cPacketQueue m_recvQueue;

		pthread_t m_handle;
		bool m_threadLoop;
		int m_sleepMillis;
		int m_recvBytes; // debug
	};


	inline bool cTCPClient::IsConnect() const { return m_isConnect; }
}
