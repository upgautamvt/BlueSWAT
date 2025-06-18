# Lines added by author
	int res;

	res = IFW_L2CAP_PACKET_PARSER(conn, buf);

	if (res == IFW_OPERATION_REJECT) {
