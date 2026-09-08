class User {
  id: string
  name: string
  email: string
  phone: string
  constructor(name: string, email: string, phone: string) {
    this.id = crypto.randomUUID()
    this.name = name
    this.email = email
    this.phone = phone
  }
}

type NotificationType = "completed" | "Pending"

class Notification1 {
  id: string
  type: NotificationType
  message: string
  constructor(type: NotificationType, message: string) {
    this.id = crypto.randomUUID()
    this.type = type
    this.message = message
  }
}

interface NotificationChannel {
  send(user: User, notification: Notification1): void
}

class WhatsAppNotificationChannel implements NotificationChannel {
  send(user: User, notification: Notification1) {
    console.log(
      "Whatsapp notification:",
      user.name,
      "message:",
      notification.message,
    )
  }
}

class SMSNotificationChannel implements NotificationChannel {
  send(user: User, notification: Notification1) {
    console.log(
      "SMS notification:",
      user.phone,
      "message:",
      notification.message,
    )
  }
}

class NotificationSystem {
  channels: NotificationChannel[] = [
    new SMSNotificationChannel(),
    new WhatsAppNotificationChannel(),
  ]

  send(user: User, notification: Notification1): void {
    for (const channel of this.channels) {
      ;() => {
        channel.send(user, notification)
      }
    }
  }
}

const system = new NotificationSystem()

const userA = new User("Jaswanth", "jaswanth@gmail.com", "9927043028")
const userB = new User("Jaswanth123", "jaswanth123@gmail.com", "99277843028")

const notificationA = new Notification1("Pending", "order is processing")
const notificationB = new Notification1("completed", "order has been delivered")

system.send(userA, notificationA)
system.send(userB, notificationB)
system.send(userA, notificationB)
system.send(userB, notificationA)
