const { Client, MessageEmbed } = require('discord.js')

const client = new Client()

exports.cmdsFunction = function(msg) {
	if (msg.content === '$callbot') {
		msg.channel.send(
			'**Beep boop...**\n\Hello, I`m here, how can I help you?\n\For help type $help.'
		)

		msg.react('✋') // ✋ = :raised_hand:
	}

  	else if (msg.content === '$votekick') {
  		if (msg.mentions.users.size) {
    		const taggedUser = msg.mentions.users.first()

    		msg.channel.send(`Vote kick for: ${taggedUser.username}`)
  		} else msg.reply('Please tag a valid user!')
	}

	else if (msg.content === '$ping') {
		msg.channel.send("Your ping is `"
			+ `${(Date.now() - msg.createdTimestamp)}` + " ms`")

		console.log('Called')
	}

	else if (msg.content === '$avatar') {
		msg.reply(msg.author.displayAvatarURL())
	}
}
