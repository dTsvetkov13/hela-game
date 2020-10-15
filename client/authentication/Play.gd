extends Button

var gameProto = preload("res://GameProtocol.gd");

# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

func _pressed():
	var packet = gameProto.Packet.new();
	var joinRoom = packet.new_JoinRoom();
	joinRoom.set_join(true);
	get_node("/root/Network").sendPacket(packet);
	pass
# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
