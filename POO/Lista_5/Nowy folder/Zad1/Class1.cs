using System;
using System.IO;
using System.Net.Mail;
using System.Net.Mime;

namespace Zad1
{
    public class SmtpFacade
    {
        private SmtpClient _client;

        public SmtpFacade(string host, int port)
        {
            _client = new SmtpClient(host, port);
        }
        public void Send(
            string from, 
            string to, 
            string subject,
            string body,
            Stream attachment,
            string attachmentMimeType)
        {
            MailMessage message = new MailMessage(
                from,
                to,
                subject,
                body);
            if (attachment != null || attachmentMimeType != null)
            {
                try
                {
                    message.Attachments.Add(new Attachment(attachment, attachmentMimeType));
                }
                catch (Exception e)
                {
                    Console.Error.WriteLine(e);
                }
            }
            try
            {
                _client.Send(message);
            }
            catch (Exception e)
            {
                Console.Error.WriteLine(e);
            }
        }
    }
}
