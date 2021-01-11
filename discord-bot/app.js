// Variables
const
	{ Client, MessageEmbed } = 		require('discord.js'),
	fs =							require('fs'),
	guild = 						require('guild'),
	client = new Client(),

	config = 						require('./config.json'),
	UpdateConfig = 					require('./updatecfg.json'),
	Update = 0

// Functions
client.on('ready', async () => {
	console.info(`Logged in as ${client.user.tag}!`)
})

const cmd = require('./commands.js')

client.on('message', async (msg) => {
	const
		args = msg.content.slice(config.prefix.length).trim().split(/ +/g),
  		command = args.shift().toLowerCase()

	cmd.cmdsFunction(msg)

	// Embed messages
	if (msg.content === '$help') {
		const msg_embed = new MessageEmbed()
            .setColor('#eb954c')
            .setTitle('SURVIVE TIME | Woozie  👈')
            .setAuthor('Help', 'https://i.ibb.co/s6swZq7/survivetimetransp.png')
            .setDescription('Commands')
            .setThumbnail('https://i.ibb.co/s6swZq7/survivetimetransp.png')
            .addFields(
                {
                    name: 'Player commands',
                    value: '$help, $votekick, $staff, $ping, $avatar, $update...'
                }
            )
            .addField('SURVIVE TIME | Woozie Bot', 'v1.0 by Emmett', true)
            .setImage('https://i.ibb.co/s6swZq7/survivetimetransp.png')
            .setTimestamp()
            .setFooter('Copyright © 2021', 'https://i.ibb.co/s6swZq7/survivetimetransp.png')

        msg.channel.send(msg_embed)
	}

	else if (msg.content === '$update') {
	    EmbedMessage(
			'Survive Time Update',
			0xd4c222,
			`**Update**:\n- ${(Update == 0 ? (UpdateConfig.noupdate) : (UpdateConfig.update))}`
		)
	}

	else if (msg.content === '$rules') {
		EmbedMessage(
			'Survive Time Rules',
			0xd4c222,
			'** RULES **\n- Zabranjeno je bilo kakvo vredjanje clanova.\n- Zabranjeno je psovanje, spam...\n- Zabranjeno je reklamiranje.\n- Zabranjeno je slanje eksplicitnih poruka, slika (nsfw)...\n- Pisati iskljucivo srpsko-hrvatskim pismom (latinicom).\n\nNe trazite role za administratora, moderatora itd, dobija se po zasluzi.'
		)
	}

	else if (msg.content === '$deletemsg') {
		const num = args.join(' ')

		for (let i = 0; i < num; ++i)
			msg.delete({ timeout: 500 })
		
		msg.channel.send('Deleted msg.')
	}

	else if (command === 'idea') {
		const text = args.join(' ')

		fs.appendFile('ideas.txt', `\n${text}`, function (err) {
			if (err)
				throw err

			console.log('Saved.')

			msg.reply(`Predlozili ste ideju: ${text}.`)
		})
	}

	else if (command === 'botmsg') {
		if (msg.member.roles.cache.has('724350090264707092') ||
			msg.member.roles.cache.has('724350492200927335') ||
			msg.member.roles.cache.has('724350314714759178')) {
			const message = args.join(" ")

			msg.delete({ timeout: 500 })
			msg.channel.send(message)
		}
	}
})

client.login(config.token)