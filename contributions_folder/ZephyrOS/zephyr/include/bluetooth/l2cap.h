# Lines added by author
// IFW below

// IFW above

 *  @brief Channel destroy callback
 *
 *  @param chan Channel object.
 */
 *  dealing with setting channel to proper state depending on operational
 *  context.
 */
	 *
	 * Once this status is notified it means the channel will no longer be
	 * able to transmit or receive data.
	 */
	 *
	 *  If this callback is provided it will be called whenever the
	 *  connection completes.
	 *
	 *  @param chan The channel that has been connected
	 */
	 *
	 *  If this callback is provided it will be called whenever the
	 *  channel is disconnected, including when a connection gets
	 *  rejected.
	 *
	 *  @param chan The channel that has been Disconnected
	 */
	 *
	 *  If this callback is provided it will be called whenever the
	 *  security level changed (indirectly link encryption done) or
	 *  authentication procedure fails. In both cases security initiator
	 *  and responder got the final status (HCI status) passed by
	 *  related to encryption and authentication events from local host's
	 *  controller.
	 *
	 *  @param chan The channel which has made encryption status changed.
	 *  @param status HCI status of performed security procedure caused
	 *  by channel security requirements. The value is populated
	 *  by HCI layer and set to 0 when success and to non-zero (reference to
	 *  HCI Error Codes) when security/authentication failed.
	 */
	 *
	 *  If this callback is provided the channel will use it to allocate
	 *  buffers to store incoming data.
	 *
	 *  @param chan The channel requesting a buffer.
	 *
	 *  @return Allocated buffer.
	 */
	 *
	 *  @param chan The channel receiving data.
	 *  @param buf Buffer containing incoming data.
	 *
	 *  @return 0 in case of success or negative value in case of error.
	 *  If -EINPROGRESS is returned user has to confirm once the data has
	 *  been processed by calling bt_l2cap_chan_recv_complete passing back
	 *  the buffer received with its original user_data which contains the
	 *  number of segments/credits used by the packet.
	 */
	 *
	 *  If this callback is provided it will be called whenever a SDU has
	 *  been completely sent.
	 *
	 *  @param chan The channel which has sent data.
	 */
	 *
	 *  If this callback is provided it will be called whenever the
	 *  channel status changes.
	 *
	 *  @param chan The channel which status changed
	 *  @param status The channel status
	 */
	 *
	 *  0               A dynamic value will be auto-allocated when
	 *                  bt_l2cap_server_register() is called.
	 *
	 *  0x0001-0x007f   Standard, Bluetooth SIG-assigned fixed values.
	 *
	 *  0x0080-0x00ff   Dynamically allocated. May be pre-set by the
	 *                  application before server registration (not
	 *                  recommended however), or auto-allocated by the
	 *                  stack if the app gave 0 as the value.
	 */
	 *
	 *  This callback is called whenever a new incoming connection requires
	 *  authorization.
	 *
	 *  @param conn The connection that is requesting authorization
	 *  @param chan Pointer to received the allocated channel
	 *
	 *  @return 0 in case of success or negative value in case of error.
	 *  Possible return values:
	 *  -ENOMEM if no available space for new channel.
	 *  -EACCES if application did not authorize the connection.
	 *  -EPERM if encryption key size is too short.
	 */
 *
 *  Register L2CAP server for a PSM, each new connection is authorized using
 *  the accept() callback which in case of success shall allocate the channel
 *  structure to be used by the new connection.
 *
 *  For fixed, SIG-assigned PSMs (in the range 0x0001-0x007f) the PSM should
 *  be assigned to server->psm before calling this API. For dynamic PSMs
 *  (in the range 0x0080-0x00ff) server->psm may be pre-set to a given value
 *  (this is however not recommended) or be left as 0, in which case upon
 *  return a newly allocated value will have been assigned to it. For
 *  dynamically allocated values the expectation is that it's exposed through
 *  a GATT service, and that's how L2CAP clients discover how to connect to
 *  the server.
 *
 *  @param server Server structure.
 *
 *  @return 0 in case of success or negative value in case of error.
 */
 *
 *  Register L2CAP server for a PSM, each new connection is authorized using
 *  the accept() callback which in case of success shall allocate the channel
 *  structure to be used by the new connection.
 *
 *  @param server Server structure.
 *
 *  @return 0 in case of success or negative value in case of error.
 */
 *
 *  Connect L2CAP channel by PSM, once the connection is completed channel
 *  connected() callback will be called. If the connection is rejected
 *  disconnected() callback is called instead.
 *  Channel object passed (over an address of it) as second parameter shouldn't
 *  be instantiated in application as standalone. Instead of, application should
 *  create transport dedicated L2CAP objects, i.e. type of bt_l2cap_le_chan for
 *  LE and/or type of bt_l2cap_br_chan for BR/EDR. Then pass to this API
 *  the location (address) of bt_l2cap_chan type object which is a member
 *  of both transport dedicated objects.
 *
 *  @param conn Connection object.
 *  @param chan Channel object.
 *  @param psm Channel PSM to connect to.
 *
 *  @return 0 in case of success or negative value in case of error.
 */
 *
 *  Disconnect L2CAP channel, if the connection is pending it will be
 *  canceled and as a result the channel disconnected() callback is called.
 *  Regarding to input parameter, to get details see reference description
 *  to bt_l2cap_chan_connect() API above.
 *
 *  @param chan Channel object.
 *
 *  @return 0 in case of success or negative value in case of error.
 */
 *
 *  Send data from buffer to the channel. If credits are not available, buf will
 *  be queued and sent as and when credits are received from peer.
 *  Regarding to first input parameter, to get details see reference description
 *  to bt_l2cap_chan_connect() API above.
 *
 *  @return Bytes sent in case of success or negative value in case of error.
 */
 *
 * Complete the reception of incoming data. This shall only be called if the
 * channel recv callback has returned -EINPROGRESS to process some incoming
 * data. The buffer shall contain the original user_data as that is used for
 * storing the credits/segments used by the packet.
 *
 * @param chan Channel object.
 * @param buf Buffer containing the data.
 *
 *  @return 0 in case of success or negative value in case of error.
 */
