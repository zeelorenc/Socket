#pragma once

#include "CNatives.h"

CString* g_pString;
extern logprintf_t logprintf;
extern CSocket* g_pSocket;

cell AMX_NATIVE_CALL n_create_socket(AMX* amx, cell* params)
{
	return (cell)g_pSocket->create_socket(params[1]);
}

cell AMX_NATIVE_CALL n_bind_socket(AMX* amx, cell* params)
{
	char* szIP;
	g_pString->Get(amx, params[2], szIP);
	cell ret_val = g_pSocket->bind_socket(params[1], szIP);
	free(szIP);
	return ret_val;
}

cell AMX_NATIVE_CALL n_set_max_connections(AMX* amx, cell* params)
{
	return (cell)g_pSocket->set_max_connections(params[1], params[2]);
}

cell AMX_NATIVE_CALL n_connect_socket(AMX* amx, cell* params)
{
	char* szHost;
	g_pString->Get(amx, params[2], szHost);
	cell ret_val = g_pSocket->connect_socket(params[1], szHost, params[3]);
	free(szHost);
	return ret_val;
}

cell AMX_NATIVE_CALL n_listen_socket(AMX* amx, cell* params)
{
	return (cell)g_pSocket->listen_socket(params[1], params[2]);
}

cell AMX_NATIVE_CALL n_stop_listen_socket(AMX* amx, cell* params)
{
	return (cell)g_pSocket->stop_listen_socket(params[1]);
}

cell AMX_NATIVE_CALL n_destroy_socket(AMX* amx, cell* params)
{
	return g_pSocket->destroy_socket(params[1]);
}

cell AMX_NATIVE_CALL n_close_remote_connection(AMX* amx, cell* params)
{
	return g_pSocket->close_remote_connection(params[1], params[2]);
}

cell AMX_NATIVE_CALL n_send_socket(AMX* amx, cell* params)
{
	char* szData;
	g_pString->Get(amx, params[2], szData);
	cell ret_val = g_pSocket->send_socket(params[1], szData, params[3]);
	free(szData);
	return ret_val;
}

cell AMX_NATIVE_CALL n_sendto_socket(AMX* amx, cell* params)
{
	char *szData, *szIP;
	g_pString->Get(amx, params[2], szIP);
	g_pString->Get(amx, params[4], szData);
	cell ret_val = g_pSocket->sendto_socket(params[1], szIP, params[3], szData, params[5]);
	free(szData);
	free(szIP);
	return ret_val;
}

cell AMX_NATIVE_CALL n_sendto_remote_client(AMX* amx, cell* params)
{
	char* szData;
	g_pString->Get(amx, params[3], szData);
	cell ret_val = g_pSocket->sendto_remote_client(params[1], params[2], szData);
	free(szData);
	return ret_val;
}

cell AMX_NATIVE_CALL n_is_remote_client_connected(AMX* amx, cell* params)
{
	return g_pSocket->is_remote_client_connected(params[1], params[2]);
}

cell AMX_NATIVE_CALL n_is_socket_valid(AMX* amx, cell* params)
{
	return g_pSocket->is_socket_valid(params[1]);
}

cell AMX_NATIVE_CALL n_get_remote_client_ip(AMX* amx, cell* params)
{
	g_pString->Set(amx, params[3], g_pSocket->get_remote_client_ip(params[1], params[2]));
	return 1;
}
cell AMX_NATIVE_CALL n_socket_send_array(AMX* amx, cell* params)
{
	cell *aData;
	amx_GetAddr(amx, params[2], &aData);
	return g_pSocket->socket_send_array(params[1], aData, params[3]);
}
